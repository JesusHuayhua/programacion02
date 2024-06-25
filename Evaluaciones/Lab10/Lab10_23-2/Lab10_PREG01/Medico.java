class Medico{
    private int codigo;
    private String nombre;
    private double tarifa;
    private double tiempoTotal;
    private double ingresosTotales;
    private int cantidadDeConsultas;

    public Medico(){
        this.codigo = 0;
        this.nombre = "";
        this.tarifa = 0.0;
        this.tiempoTotal = 0.0;
        this.ingresosTotales = 0.0;
        this.cantidadDeConsultas = 0;
    }
    
    public Medico(int codigo,String nombre, double tarifa, double tiempoTotal, double ingresosTotales, int cantidadDeConsultas){
        this.codigo = codigo;
        this.nombre = nombre;
        this.tarifa = tarifa;
        this.tiempoTotal = tiempoTotal;
        this.ingresosTotales = ingresosTotales;
        this.cantidadDeConsultas = cantidadDeConsultas;
    }

    public void SetCodigo(int codigo){
        this.codigo = codigo;
    }

    public int GetCodigo(){
        return this.codigo;
    }

    public void SetNombre(String nombre){
        this.nombre = nombre;
    }

    public String GetNombre(){
        return this.nombre;
    }

    public void SetTarifa(double tarifa){
        this.tarifa = tarifa;
    }

    public double GetTarifa(){
        return this.tarifa;
    }

    public void SetTiempoTotal(double tiempoTotal){
        this.tiempoTotal = tiempoTotal;
    }

    public double GetTiempoTotal(){
        return this.tiempoTotal;
    }

    public void SetIngresosTotales(double ingresosTotales){
        this.ingresosTotales = ingresosTotales;
    }

    public double GetIngresosTotales(){
        return this.ingresosTotales;
    }

    public void SetCantidadDeConsultas(int cantidadDeConsultas){
        this.cantidadDeConsultas = cantidadDeConsultas;
    }

    public int GetCantidadDeConsultas(){
        return this.cantidadDeConsultas;
    }
    
}