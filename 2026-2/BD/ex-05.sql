-- 1) Criar as tabelas pessoa e automovel

CREATE DATABASE IF NOT EXISTS concesionaria;
USE concesionaria;

DROP TABLE IF EXISTS automovel;
DROP TABLE IF EXISTS pessoa;

CREATE TABLE pessoa (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(45) NOT NULL,
    modelo VARCHAR(45) NOT NULL,
    profissao VARCHAR(45) NOT NULL,
    cnh VARCHAR(1) NOT NULL DEFAULT '0'
);

CREATE TABLE automovel (
    id_automovel INT AUTO_INCREMENT PRIMARY KEY,
    id_pessoa INT NOT NULL,
    tipo VARCHAR(10) NOT NULL,
    modelo VARCHAR(45) NOT NULL,
    preco DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (id_pessoa) REFERENCES pessoa(id)
);

-- 2) Inserir pelo menos 5 registros em cada tabela
-- Devem existir pessoas sem automovel e com mais de 1

INSERT INTO pessoa (nome, modelo, profissao, cnh) VALUES
('Carlos Silva', 'Gol', 'Desenvolvedor', 'S'),
('Ana Oliveira', 'Onix', 'Médico', 'S'),
('Bruno Costa', 'HB20', 'Professor', 'N'),
('Maria Santos', 'Tracker', 'Advogado', 'S'),
('Pedro Almeida', 'Mobi', 'Designer', 'S'),
('Julia Ferreira', 'Fox', 'Contador', 'N'),
('Lucas Lima', 'Creta', 'Engenheiro', 'S');

INSERT INTO automovel (id_pessoa, tipo, modelo, preco) VALUES
(1, 'Carro', 'Gol', 45000.00),
(1, 'Moto', 'Honda CG 160', 12000.00),
(2, 'Carro', 'Onix', 85000.00),
(4, 'Carro', 'Tracker', 95000.00),
(5, 'Moto', 'Yamaha Factor', 10500.00),
(5, 'Carro', 'Mobi', 55000.00),
(7, 'Carro', 'Creta', 120000.00),
(7, 'Moto', 'Honda CG 250', 18000.00);

-- 3) Buscar e exibir todas as informações de pessoas,
--    mas ao invés de mostrar 'S' ou 'N' na coluna cnh,
--    mostrar 'Sim' ou 'Não'

SELECT
    id,
    nome,
    modelo,
    profissao,
    CASE cnh
        WHEN 'S' THEN 'Sim'
        WHEN 'N' THEN 'Não'
        ELSE 'Não informado'
    END AS cnh
FROM pessoa;

-- 4) Buscar e exibir o nome da pessoa e a quantidade
--    de automóveis que possui

SELECT
    p.nome,
    COUNT(a.id_automovel) AS qtd_automoveis
FROM pessoa p
LEFT JOIN automovel a ON p.id = a.id_pessoa
GROUP BY p.id, p.nome;

-- 5) Buscar e exibir o nome de todas as pessoas e,
--    se tiver automóvel, mostrar se é 'Moto' ou 'Carro'
--    e o modelo

SELECT
    p.nome,
    CASE
        WHEN a.id_automovel IS NULL THEN 'Sem automóvel'
        ELSE CONCAT(a.tipo, ' - ', a.modelo)
    END AS automovel
FROM pessoa p
LEFT JOIN automovel a ON p.id = a.id_pessoa;

-- 6) Criar a tabela pessoa_automovel com os campos
--    nome da pessoa, modelo e preço do automóvel

DROP TABLE IF EXISTS pessoa_automovel;

CREATE TABLE pessoa_automovel (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    modelo VARCHAR(45) NOT NULL,
    preco DECIMAL(10,2) NOT NULL
);

-- 7) Utilizando subquery, inserir na nova tabela as
--    informações somente das pessoas que possuem automóveis

INSERT INTO pessoa_automovel (nome, modelo, preco)
SELECT
    (SELECT p.nome FROM pessoa p WHERE p.id = a.id_pessoa),
    a.modelo,
    a.preco
FROM automovel a
WHERE a.id_pessoa IN (SELECT p.id FROM pessoa p);

-- 8) Buscar e exibir o nome da pessoa e o preço total
--    de seus automóveis, ordenando da mais cara para a
--    mais barata

SELECT
    p.nome,
    SUM(a.preco) AS preco_total
FROM pessoa p
JOIN automovel a ON p.id = a.id_pessoa
GROUP BY p.id, p.nome
ORDER BY preco_total DESC;

-- 9) Atualize o preço de algum automóvel

UPDATE automovel
SET preco = 48000.00
WHERE id_automovel = 1;

-- 10) Utilizando subquery, atualize na nova tabela o preço
--     de todos os registros do automóvel que teve o preço
--     atualizado

UPDATE pessoa_automovel
SET preco = (
    SELECT a.preco
    FROM automovel a
    WHERE a.modelo = pessoa_automovel.modelo AND a.id_pessoa = 1
)
WHERE modelo IN (
    SELECT a.modelo
    FROM automovel a
    WHERE a.modelo = 'Gol' AND a.id_pessoa = 1
);

-- 11) Utilizando subquery, busque na nova tabela quais
--     são os automóveis das pessoas que a profissão é
--     "Desenvolvedor" ou "Médico"

SELECT *
FROM pessoa_automovel
WHERE nome IN (
    SELECT p.nome
    FROM pessoa p
    WHERE p.profissao IN ('Desenvolvedor', 'Médico')
);

-- 12) Criar um índice para a nova tabela utilizando
--     a coluna modelo

CREATE INDEX idx_modelo ON pessoa_automovel(modelo);

-- 13) Utilizando as tabelas (nova tabela e pessoa) mostrar
--     o nome e profissão de todas as pessoas que não tem
--     nenhum automóvel

SELECT p.nome, p.profissao
FROM pessoa p
WHERE p.id NOT IN (
    SELECT a.id_pessoa
    FROM automovel a
);
