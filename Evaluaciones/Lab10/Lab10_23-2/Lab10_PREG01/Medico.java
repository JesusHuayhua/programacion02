import java.util.ArrayList;
import java.util.Scanner;
class Medico{
    private int codigo;
    private String nombre;
    private String especialidad;
    private double tarifa;
    private double tiempoTotal;
    private double ingresosTotales;
    private int cantidadDeConsultas;

    public Medico(){
        this.codigo = 0;
        this.nombre = "";
        this.especialidad = "";
        this.tarifa = 0.0;
        this.tiempoTotal = 0.0;
        this.ingresosTotales = 0.0;
        this.cantidadDeConsultas = 0;
    }
    
    public Medico(int codigo,String nombre,String especialidad, double tarifa, double tiempoTotal, double ingresosTotales, int cantidadDeConsultas){
        this.codigo = codigo;
        this.nombre = nombre;
        this.especialidad = especialidad;
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
    //50611  EDGAR_MUNOZ_VERGEL    Urologia  112.85
    //15092     LUZ_SOFIA_JAUREGUI_BRAVO     Dermatologia     250.15
    public boolean leerMedico(Scanner arch){
      this.codigo = arch.nextInt();
      if(this.codigo == 0) return false;
      this.nombre = arch.next();
      this.especialidad = arch.next();
      this.tarifa = arch.nextDouble();
      return true;
    }
      
    public void imprimirMedico(){
      System.out.printf("Codigo: %-10d Nombre: %-40s Especialidad: %-20s, Tarifa: %-10.2f TiempoTotal: %-10.2f, IngresosTotales: %-10.2f, CantidadDeConsultas: %d\n",
      this.codigo,this.nombre, this.especialidad, this.tarifa, this.tiempoTotal, this.ingresosTotales,this.cantidadDeConsultas);
      
    }
    
    
}