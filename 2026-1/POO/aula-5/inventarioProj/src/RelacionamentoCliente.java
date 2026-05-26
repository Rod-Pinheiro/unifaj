public abstract class RelacionamentoCliente {
    private String codigo;
    private Cliente cliente;

    public RelacionamentoCliente(String codigo, Cliente cliente) {
        this.codigo = codigo;
        this.cliente = cliente;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public abstract void detalharRelacionamento();
}
