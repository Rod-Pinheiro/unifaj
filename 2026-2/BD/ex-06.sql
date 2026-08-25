-- 1) Criar as tabelas filme e personagem

DROP TABLE IF EXISTS personagem;
DROP TABLE IF EXISTS filme;

CREATE TABLE filme (
    id INT AUTO_INCREMENT PRIMARY KEY,
    titulo VARCHAR(100) NOT NULL,
    tipo VARCHAR(100) NOT NULL,
    diretor VARCHAR(100) NOT NULL,
    ano_lancamento INT NOT NULL
);

CREATE TABLE personagem (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    especie VARCHAR(100) NOT NULL,
    nivel_importancia INT NOT NULL,
    id_filme INT NOT NULL,
    FOREIGN KEY (id_filme) REFERENCES filme(id)
);

-- 2) Inserir pelo menos 3 filmes e 10 personagens

INSERT INTO filme (titulo, tipo, diretor, ano_lancamento) VALUES
('O Poderoso Chefão', 'Drama', 'Francis Ford Coppola', 1972),
('Vingadores: Guerra Infinita', 'Ação', 'Anthony Russo', 2018),
('A Origem', 'Ficção Científica', 'Christopher Nolan', 2010),
('Clube da Luta', 'Drama', 'David Fincher', 1999),
('John Wick', 'Ação', 'Chad Stahelski', 2014);

INSERT INTO personagem (nome, especie, nivel_importancia, id_filme) VALUES
('Don Corleone', 'Humano', 1, 1),
('Michael Corleone', 'Humano', 2, 1),
('Thanos', 'Titã', 1, 2),
('Homem de Ferro', 'Humano', 2, 2),
('Capitão América', 'Humano', 3, 2),
('Viúva Negra', 'Humano', 4, 2),
('Dom Cobb', 'Humano', 1, 3),
('Arthur', 'Humano', 2, 3),
('Tyler Durden', 'Humano', 1, 4),
('O Narrador', 'Humano', 2, 4),
('John Wick', 'Humano', 1, 5),
('Cães', 'Animal', 2, 5);

-- 3) Buscar o nome do filme e a quantidade de personagens

SELECT
    f.titulo,
    COUNT(p.id) AS qtd_personagens
FROM filme f
LEFT JOIN personagem p ON f.id = p.id_filme
GROUP BY f.id, f.titulo;

-- 4) Buscar o nome do diretor e a quantidade de filmes
--    dirigidos por ele

SELECT
    f.diretor,
    COUNT(f.id) AS qtd_filmes
FROM filme f
GROUP BY f.diretor;

-- 5) Buscar o nome, espécie e nível de importância de todos
--    os personagens, ordenando pelo ano de lançamento do filme
--    e por ordem do mais importante para o menos importante

SELECT
    p.nome,
    p.especie,
    p.nivel_importancia
FROM personagem p
JOIN filme f ON p.id_filme = f.id
ORDER BY f.ano_lancamento, p.nivel_importancia;

-- 6) Buscar o título do filme e o nome dos personagens
--    que o filme é de ação ou drama

SELECT
    f.titulo,
    p.nome
FROM filme f
JOIN personagem p ON f.id = p.id_filme
WHERE f.tipo IN ('Ação', 'Drama');

-- 7) Mostrar em uma única coluna o nome do diretor e dos
--    personagens ordenado por ordem alfabética

SELECT diretor AS nome FROM filme
UNION
SELECT nome FROM personagem
ORDER BY nome;

-- 8) Criar uma view chamada "view_filme" com as informações:
--    título e tipo

CREATE OR REPLACE VIEW view_filme AS
SELECT titulo, tipo
FROM filme;

-- 9) Buscar na "view_filme" todas as informações ordenadas
--    pelo título do filme

SELECT *
FROM view_filme
ORDER BY titulo;

-- 10) Criar uma view chamada "view_personagem" com as
--     informações: nome, espécie e id do filme

CREATE OR REPLACE VIEW view_personagem AS
SELECT nome, especie, id_filme
FROM personagem;

-- 11) Utilizando a "view_personagem" buscar o nome do
--     personagem e o título do filme

SELECT
    vp.nome,
    f.titulo
FROM view_personagem vp
JOIN filme f ON vp.id_filme = f.id;

-- 12) Criar uma view chamada "view_filme_personagem" com
--     as informações: título do filme, tipo, diretor, ano
--     de lançamento e nome do personagem de todos os filmes
--     que o ano de lançamento é par

CREATE OR REPLACE VIEW view_filme_personagem AS
SELECT
    f.titulo,
    f.tipo,
    f.diretor,
    f.ano_lancamento,
    p.nome AS nome_personagem
FROM filme f
JOIN personagem p ON f.id = p.id_filme
WHERE f.ano_lancamento % 2 = 0;

-- 13) Buscar o título de todos os filmes que o ano de
--     lançamento não é par. Não pode utilizar no filtro
--     da busca a coluna "ano_lancamento"

SELECT titulo
FROM filme
WHERE id NOT IN (
    SELECT id FROM view_filme_personagem
);

-- 14) Buscar o título do filme, tipo, diretor, ano de
--     lançamento e nome do personagem que não estão na
--     "view_filme_personagem"

SELECT
    f.titulo,
    f.tipo,
    f.diretor,
    f.ano_lancamento,
    p.nome AS nome_personagem
FROM filme f
JOIN personagem p ON f.id = p.id_filme
WHERE (f.titulo, f.tipo, f.diretor, f.ano_lancamento, p.nome) NOT IN (
    SELECT titulo, tipo, diretor, ano_lancamento, nome_personagem
    FROM view_filme_personagem
);
