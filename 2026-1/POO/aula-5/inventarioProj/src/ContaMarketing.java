public class ContaMarketing extends RelacionamentoCliente {
    private String campanha;

    public ContaMarketing(String codigo, Cliente cliente, String campanha) {
        super(codigo, cliente);
        this.campanha = campanha;
    }

    public String getCampanha() {
        return campanha;
    }

    public void setCampanha(String campanha) {
        this.campanha = campanha;
    }

    @Override
    public void detalharRelacionamento() {
        System.out.println("ContaMarketing [codigo=" + getCodigo() + ", cliente=" + getCliente().getNome()
                + ", campanha=" + campanha + "]");
    }
}
