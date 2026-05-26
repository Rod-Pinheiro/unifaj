public class Mesa extends Patrimonio {
    private int numeroLugares;

    public Mesa(String codigo, String descricao, int numeroLugares) {
        super(codigo, descricao);
        this.numeroLugares = numeroLugares;
    }

    public int getNumeroLugares() {
        return numeroLugares;
    }

    public void setNumeroLugares(int numeroLugares) {
        this.numeroLugares = numeroLugares;
    }

    @Override
    public void exibirItem() {
        System.out.println("Mesa [codigo=" + getCodigo() + ", descricao=" + getDescricao()
                + ", numeroLugares=" + numeroLugares + "]");
    }
}
