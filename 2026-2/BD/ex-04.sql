-- 1) Criar as tabelas pai e filho

DROP TABLE IF EXISTS filho;
DROP TABLE IF EXISTS pai;

CREATE TABLE pai (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL
);

CREATE TABLE filho (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    id_pai INT NOT NULL,
    FOREIGN KEY (id_pai) REFERENCES pai(id)
);

-- 2) Inserir pelo menos 5 registros em cada tabela
-- Com nomes iguais e diferentes

INSERT INTO pai (nome) VALUES
('Carlos'),
('João'),
('Pedro'),
('Ana'),
('Lucas'),
('Maria');

INSERT INTO filho (nome, id_pai) VALUES
('Carlos', 1),
('Carlos', 2),
('João', 2),
('Pedro', 3),
('Ana', 4),
('Lucas', 4),
('Pedro', 5),
('Maria', 6);

-- 3) Buscar e exibir em 2 colunas o nome do pai e o
--    nome do filho

SELECT
    p.nome AS pai,
    f.nome AS filho
FROM pai p
JOIN filho f ON p.id = f.id_pai;

-- 4) Buscar e exibir em 1 coluna só o nome de todos os
--    pais e o nome de todos os filhos em ordem ascendente

SELECT nome FROM pai
UNION ALL
SELECT nome FROM filho
ORDER BY nome;

-- 5) Buscar e exibir em 1 coluna só o nome de todos os
--    pais e filhos sem duplicidade dos nomes

SELECT nome FROM pai
UNION
SELECT nome FROM filho;

-- 6) Buscar e exibir em 1 coluna só os nomes que são
--    comuns entre pais e filhos

SELECT nome FROM pai
INTERSECT
SELECT nome FROM filho;

-- 7) Buscar e exibir em 1 coluna só o nome de todos os
--    pais que o nome não é de algum filho

SELECT nome FROM pai
EXCEPT
SELECT nome FROM filho;

-- 8) Buscar e exibir em 1 coluna só o nome de todos os
--    pais e filhos, mas o nome do pai não pode ser de
--    algum filho e vice-versa

SELECT nome FROM pai
EXCEPT
SELECT nome FROM filho
UNION
SELECT nome FROM filho
EXCEPT
SELECT nome FROM pai;

-- 9) Buscar o nome do pai e a quantidade de filhos

SELECT
    p.nome,
    COUNT(f.id) AS qtd_filhos
FROM pai p
LEFT JOIN filho f ON p.id = f.id_pai
GROUP BY p.id, p.nome;

-- 10) Buscar e exibir o nome e a quantidade de pessoas
--     (pais + filhos) que possuem esse nome

SELECT
    nome,
    COUNT(*) AS qtd_pessoas
FROM (
    SELECT nome FROM pai
    UNION ALL
    SELECT nome FROM filho
) AS todos
GROUP BY nome;

-- 11) Buscar o nome somente do pai que tem 2 ou mais
--     filhos

SELECT p.nome
FROM pai p
JOIN filho f ON p.id = f.id_pai
GROUP BY p.id, p.nome
HAVING COUNT(f.id) >= 2;

-- 12) Repetir o item 11, porém utilizando o WITH

WITH contagem AS (
    SELECT
        p.id,
        p.nome,
        COUNT(f.id) AS qtd_filhos
    FROM pai p
    LEFT JOIN filho f ON p.id = f.id_pai
    GROUP BY p.id, p.nome
)
SELECT nome
FROM contagem
WHERE qtd_filhos >= 2;

-- 13) Criar uma tabela pai_filho para guardar o par de
--     informações: nome do pai e nome do filho

DROP TABLE IF EXISTS pai_filho;

CREATE TABLE pai_filho (
    nome_pai VARCHAR(100) NOT NULL,
    nome_filho VARCHAR(100) NOT NULL
);

-- 14) Utilizando o WITH escrever todas as informações de
--     pai e filho na tabela pai_filho

WITH dados AS (
    SELECT
        p.nome AS nome_pai,
        f.nome AS nome_filho
    FROM pai p
    JOIN filho f ON p.id = f.id_pai
)
INSERT INTO pai_filho (nome_pai, nome_filho)
SELECT nome_pai, nome_filho
FROM dados;
