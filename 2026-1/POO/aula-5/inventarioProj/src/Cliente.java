public class Cliente extends Pessoa {
    private String empresa;

    public Cliente(int id, String nome, String empresa) {
        super(id, nome);
        this.empresa = empresa;
    }

    public String getEmpresa() {
        return empresa;
    }

    public void setEmpresa(String empresa) {
        this.empresa = empresa;
    }

    @Override
    public void exibirDados() {
        System.out.println("Cliente [id=" + getId() + ", nome=" + getNome() + ", empresa=" + empresa + "]");
    }
}
