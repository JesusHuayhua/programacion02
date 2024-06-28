import java.util.ArrayList;
import java.util.Scanner;

class Paciente{
    private int dni;
    private String nombre;
    private String distrito;
    private double tiempoTotal;
    private double gastosTotales;
    private int cantidadDeConsultas;

    public Paciente(){
        this.dni = 0;
        this.nombre = "";
        this.distrito = "";
        this.tiempoTotal  = 0.0;
        this.gastosTotales = 0.0;
        this.cantidadDeConsultas = 0;
    }

    public Paciente(int dni,String nombre, String distrito, double tiempoTotal, double gastosTotales, int cantidadDeConsultas){
        this.dni = dni;
        this.nombre = nombre;
        this.distrito = distrito;
        this.tiempoTotal = tiempoTotal;
        this.gastosTotales = gastosTotales;
        this.cantidadDeConsultas = cantidadDeConsultas;
    }

    public void SetDni(int dni){
        this.dni = dni;
    }

    public int GetDni(){
        return this.dni;
    }

    public void SetNombre(String nombre){
        this.nombre = nombre;
    }

    public String GetNombre(){
        return this.nombre;
    }    

    public void SetDistrito(String distrito){
        this.distrito = distrito;
    }

    public String GetDistrito(){
        return this.distrito;
    }

    public void SetTiempoTotal(double tiempoTotal){
        this.tiempoTotal = tiempoTotal;
    }

    public double GetTiempoTotal(){
        return this.tiempoTotal;
    }

    public void SetGastosTotales(double gastosTotales){
        this.gastosTotales = gastosTotales;
    }

    public double GetGastosTotales(){
        return this.gastosTotales;
    }

    public void SetCantidadDeConsultas(int cantidadDeConsultas){
        this.cantidadDeConsultas = cantidadDeConsultas;
    }

    public int GetCantidadDeConsultas(){
        return this.cantidadDeConsultas;
    }
    
  //  45201670  ROCIO_YOLANDA_ACUNA_YINO Santa_Anita
//59561864     GONZALO_VEGA_MUNOZ     Santiago_de_Surco
    public boolean leerPaciente(Scanner arch){
      this.dni = arch.nextInt();
      if(this.dni == 0) return false;
      this.nombre =  arch.next();
      this.distrito = arch.next();
      return true;
    }
      
    public void imprimirPaciente(){    
      System.out.printf("Codigo: %-10d Nombre: %-40s, TiempoTotal: %-10.2f, GastosTotales: %-10.2f, CantidadDeConsultas: %d\n",
      this.dni,this.nombre, this.tiempoTotal, this.gastosTotales,this.cantidadDeConsultas);
      
    }
    

}