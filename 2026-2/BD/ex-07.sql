-- 1) Criar as tabelas animal e animal_feroz

DROP TABLE IF EXISTS animal_feroz;
DROP TABLE IF EXISTS animal;

CREATE TABLE animal (
    id INT AUTO_INCREMENT PRIMARY KEY,
    especie VARCHAR(100) NOT NULL,
    nivel_feroz INT NOT NULL,
    herbivoro_carnivoro VARCHAR(1) NOT NULL
);

CREATE TABLE animal_feroz (
    id INT PRIMARY KEY,
    especie VARCHAR(100) NOT NULL,
    herbivoro_carnivoro VARCHAR(1) NOT NULL,
    registros INT NOT NULL
);

-- 2) Criar um trigger para antes de inserir um animal
--    verificar se o nivel_feroz está entre 1 e 5.
--    Se sim ok, senão exibir mensagem erro

DELIMITER //

CREATE TRIGGER trg_animal_bi_nivel_feroz
BEFORE INSERT ON animal
FOR EACH ROW
BEGIN
    IF NEW.nivel_feroz < 1 OR NEW.nivel_feroz > 5 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Erro: nivel_feroz deve estar entre 1 e 5';
    END IF;
END//

-- 3) Criar um trigger para depois de inserir um animal
--    verificar se o nivel_feroz for 4 ou 5 deve cadastrar
--    esse animal na tabela animal_feroz e atribuir 1 para
--    registros

CREATE TRIGGER trg_animal_ai_feroz
AFTER INSERT ON animal
FOR EACH ROW
BEGIN
    IF NEW.nivel_feroz IN (4, 5) THEN
        INSERT INTO animal_feroz (id, especie, herbivoro_carnivoro, registros)
        VALUES (NEW.id, NEW.especie, NEW.herbivoro_carnivoro, 1);
    END IF;
END//

DELIMITER ;

-- 4) Criar 6 animais (5 com sucesso e 1 com nivel_feroz
--    inválido)

INSERT INTO animal (especie, nivel_feroz, herbivoro_carnivoro) VALUES
('Coelho', 1, 'H'),
('Gato', 2, 'C'),
('Lobo', 3, 'C'),
('Tubarão', 4, 'C'),
('Leão', 5, 'C');

-- O 6º animal tem nivel_feroz = 6 (inválido), o trigger do
-- item 2 bloqueia a inserção
INSERT INTO animal (especie, nivel_feroz, herbivoro_carnivoro)
VALUES ('Cachorro', 6, 'C');

-- 5) Criar um trigger para antes de atualizar um animal
--    verificar se está mudando a espécie. Se sim, não
--    deixar atualizar

DELIMITER //

CREATE TRIGGER trg_animal_bu_especie
BEFORE UPDATE ON animal
FOR EACH ROW
BEGIN
    IF NEW.especie <> OLD.especie THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Erro: não é permitido alterar a espécie';
    END IF;
END//

-- 6) Atualizar um animal e mudar a espécie dele para
--    "espécie inválida" (o trigger do item 5 bloqueia)

UPDATE animal SET especie = 'espécie inválida' WHERE id = 1;

DELIMITER ;

-- 7) Criar um trigger para depois de atualizar um animal
--    incrementar o valor de registros daquele animal se
--    for feroz

DELIMITER //

CREATE TRIGGER trg_animal_au_registros
AFTER UPDATE ON animal
FOR EACH ROW
BEGIN
    IF NEW.nivel_feroz IN (4, 5) THEN
        UPDATE animal_feroz
        SET registros = registros + 1
        WHERE id = NEW.id;
    END IF;
END//

DELIMITER ;

-- 8) Atualizar 1 animal feroz e atualizar 1 animal que não
--    é feroz

-- Leão (nivel_feroz 5, feroz): continua feroz, incrementa
-- registros na tabela animal_feroz
UPDATE animal SET nivel_feroz = 4 WHERE id = 5;

-- Gato (nivel_feroz 2, não feroz): não altera a tabela
-- animal_feroz
UPDATE animal SET nivel_feroz = 3 WHERE id = 2;

-- 9) Criar um trigger para antes de deletar um animal
--    verificar se é herbívoro e não permitir

DELIMITER //

CREATE TRIGGER trg_animal_bd_herbivoro
BEFORE DELETE ON animal
FOR EACH ROW
BEGIN
    IF OLD.herbivoro_carnivoro = 'H' THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Erro: herbívoros não podem ser removidos';
    END IF;
END//

-- 10) Apagar um animal herbívoro (Coelho, id 1: o trigger
--     do item 9 bloqueia)

DELETE FROM animal WHERE id = 1;

-- 11) Criar um trigger para depois de deletar um animal
--     apagar ele da tabela animal_feroz

CREATE TRIGGER trg_animal_ad_feroz
AFTER DELETE ON animal
FOR EACH ROW
BEGIN
    DELETE FROM animal_feroz WHERE id = OLD.id;
END//

DELIMITER ;

-- 12) Apagar um animal que o nivel_feroz é 4 ou 5
--     (Tubarão, id 4: é carnívoro, o delete é permitido e
--     o trigger do item 11 remove da animal_feroz)

DELETE FROM animal WHERE id = 4;

-- 13) Criar uma função que recebe como parâmetro a espécie
--     do animal e retorna "Animal feroz!" ou "Animal não é
--     muito feroz!" dependendo se ele existe ou não na
--     tabela animal_feroz

DELIMITER //

CREATE FUNCTION eh_feroz(p_especie VARCHAR(100))
RETURNS VARCHAR(50)
DETERMINISTIC
READS SQL DATA
BEGIN
    DECLARE v_qtd INT;

    SELECT COUNT(*)
    INTO v_qtd
    FROM animal_feroz
    WHERE especie = p_especie;

    IF v_qtd > 0 THEN
        RETURN 'Animal feroz!';
    ELSE
        RETURN 'Animal não é muito feroz!';
    END IF;
END//

-- 14) Buscar todas as informações de todos os animais e
--     também chamar a função para falar se é ou não feroz

SELECT
    a.id,
    a.especie,
    a.nivel_feroz,
    a.herbivoro_carnivoro,
    eh_feroz(a.especie) AS situacao
FROM animal a;

DELIMITER ;

-- 15) Criar uma função que recebe como parâmetro a letra
--     inicial de herbívoro ou carnívoro e retorna o texto
--     "Herbívoro" ou "Carnívoro" conforme a entrada

DELIMITER //

CREATE FUNCTION tipo_alimentacao(p_letra VARCHAR(1))
RETURNS VARCHAR(20)
DETERMINISTIC
BEGIN
    DECLARE v_tipo VARCHAR(20);

    IF UPPER(p_letra) = 'H' THEN
        SET v_tipo = 'Herbívoro';
    ELSEIF UPPER(p_letra) = 'C' THEN
        SET v_tipo = 'Carnívoro';
    ELSE
        SET v_tipo = 'Inválido';
    END IF;

    RETURN v_tipo;
END//

-- 16) Buscar a espécie e chamar a função que fala se é
--     Herbívoro ou Carnívoro

SELECT
    a.especie,
    tipo_alimentacao(a.herbivoro_carnivoro) AS tipo
FROM animal a;

DELIMITER ;