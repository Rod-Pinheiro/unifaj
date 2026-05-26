import java.util.ArrayList;
import java.util.List;

public class Funcionario extends Pessoa {
    private String cargo;
    private List<Patrimonio> patrimonios;

    public Funcionario(int id, String nome, String cargo) {
        super(id, nome);
        this.cargo = cargo;
        this.patrimonios = new ArrayList<>();
    }

    public String getCargo() {
        return cargo;
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    public void vincularPatrimonio(Patrimonio p) {
        patrimonios.add(p);
    }

    public List<Patrimonio> getPatrimonios() {
        return patrimonios;
    }

    @Override
    public void exibirDados() {
        System.out.println("Funcionario [id=" + getId() + ", nome=" + getNome() + ", cargo=" + cargo + "]");
    }
}
