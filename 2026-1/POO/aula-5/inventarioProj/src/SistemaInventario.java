import java.util.ArrayList;
import java.util.List;

public class SistemaInventario implements Relatorio {
    private String ra;
    private String nomeAluno;
    private List<Funcionario> funcionarios;
    private List<Cliente> clientes;
    private List<Patrimonio> patrimonios;
    private List<RelacionamentoCliente> relacionamentos;

    public SistemaInventario() {
        this.funcionarios = new ArrayList<>();
        this.clientes = new ArrayList<>();
        this.patrimonios = new ArrayList<>();
        this.relacionamentos = new ArrayList<>();
    }

    public void setRa(String ra) {
        this.ra = ra;
    }

    public void setNomeAluno(String nomeAluno) {
        this.nomeAluno = nomeAluno;
    }

    public void adicionarFuncionario(Funcionario f) {
        funcionarios.add(f);
    }

    public void adicionarCliente(Cliente c) {
        clientes.add(c);
    }

    public void adicionarPatrimonio(Patrimonio p) {
        patrimonios.add(p);
    }

    public void adicionarRelacionamento(RelacionamentoCliente r) {
        relacionamentos.add(r);
    }

    @Override
    public void gerarRelatorio() {
        System.out.println("RA: " + ra);
        System.out.println("Nome: " + nomeAluno);
        System.out.println();

        System.out.println("===== FUNCIONARIOS =====");
        for (Funcionario f : funcionarios) {
            f.exibirDados();
        }

        System.out.println("\n===== CLIENTES =====");
        for (Cliente c : clientes) {
            c.exibirDados();
        }

        System.out.println("\n===== PATRIMONIO =====");
        for (Patrimonio p : patrimonios) {
            p.exibirItem();
        }

        System.out.println("\n===== RELACIONAMENTOS =====");
        for (RelacionamentoCliente r : relacionamentos) {
            r.detalharRelacionamento();
        }

        System.out.println("\n===== VINCULOS =====");
        for (Funcionario f : funcionarios) {
            System.out.println("--- Bens de " + f.getNome() + " ---");
            for (Patrimonio p : f.getPatrimonios()) {
                p.exibirItem();
            }
        }
    }
}
