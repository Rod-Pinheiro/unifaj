public class Main {
    public static void main(String[] args) {
        // ==================== PATRIMONIO ====================
        Mesa mesa1 = new Mesa("M1", "Mesa de escritorio preta", 4);
        Notebook notebook1 = new Notebook("N1", "Notebook Dell Latitude", "Dell");

        // ==================== FUNCIONARIOS ====================
        Funcionario f1 = new Funcionario(1, "Carlos", "Analista");
        Funcionario f2 = new Funcionario(2, "Ana", "Desenvolvedora");

        f1.vincularPatrimonio(mesa1);
        f2.vincularPatrimonio(mesa1);
        f2.vincularPatrimonio(notebook1);

        // ==================== CLIENTES ====================
        Cliente cl1 = new Cliente(101, "Empresa Alpha", "Alpha S.A.");
        Cliente cl2 = new Cliente(102, "Empresa Beta", "Beta Ltda.");

        // ==================== RELACIONAMENTOS ====================
        Contrato co1 = new Contrato("Co1", cl1, "2025-01-15");
        ContaMarketing ct1 = new ContaMarketing("Ct1", cl2, "Campanha Verao 2026");

        // ==================== SISTEMA ====================
        SistemaInventario sistema = new SistemaInventario();
        sistema.setRa("12530689");
        sistema.setNomeAluno("Rodolfo Rodrigues Pinheiro");
        sistema.adicionarFuncionario(f1);
        sistema.adicionarFuncionario(f2);
        sistema.adicionarCliente(cl1);
        sistema.adicionarCliente(cl2);
        sistema.adicionarPatrimonio(mesa1);
        sistema.adicionarPatrimonio(notebook1);
        sistema.adicionarRelacionamento(co1);
        sistema.adicionarRelacionamento(ct1);

        // ==================== RELATORIO GERAL ====================
        sistema.gerarRelatorio();
    }
}
