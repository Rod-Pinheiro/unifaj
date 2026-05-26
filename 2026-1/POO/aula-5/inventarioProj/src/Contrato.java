public class Contrato extends RelacionamentoCliente {
    private String dataInicio;

    public Contrato(String codigo, Cliente cliente, String dataInicio) {
        super(codigo, cliente);
        this.dataInicio = dataInicio;
    }

    public String getDataInicio() {
        return dataInicio;
    }

    public void setDataInicio(String dataInicio) {
        this.dataInicio = dataInicio;
    }

    @Override
    public void detalharRelacionamento() {
        System.out.println("Contrato [codigo=" + getCodigo() + ", cliente=" + getCliente().getNome()
                + ", dataInicio=" + dataInicio + "]");
    }
}
