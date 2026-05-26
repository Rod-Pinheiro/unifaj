public class Notebook extends Patrimonio {
    private String marca;

    public Notebook(String codigo, String descricao, String marca) {
        super(codigo, descricao);
        this.marca = marca;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    @Override
    public void exibirItem() {
        System.out.println("Notebook [codigo=" + getCodigo() + ", descricao=" + getDescricao()
                + ", marca=" + marca + "]");
    }
}
