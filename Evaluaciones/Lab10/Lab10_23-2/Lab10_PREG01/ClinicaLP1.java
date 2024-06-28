import java.util.ArrayList;
import java.util.Scanner;

class ClinicaLP1{
    private ArrayList <Medico> medicos;
    private ArrayList <Paciente> pacientes;
    public ClinicaLP1(){
        this.medicos = new ArrayList<Medico>();
        this.pacientes = new ArrayList<Paciente>();
    }
      
    public void leerDatos(){
      Scanner arch = new Scanner(System.in);
      this.leerMedicos(arch);
      this.leerPacientes(arch);
      this.leerConsultas(arch);
    }
    
    public void leerMedicos(Scanner arch){
      Medico medico;
      while(true){
        medico = new Medico();
        boolean lee = medico.leerMedico(arch);
        if(lee == false) break;
        this.medicos.add(medico);
      }
    }
    
    public void leerPacientes(Scanner arch){
      Paciente paciente;
      while(true){
        paciente = new Paciente();
        boolean lee = paciente.leerPaciente(arch);
        if(lee == false) break;
        this.pacientes.add(paciente);
      }
    }
    
    
    /*
    94683380   60934 12  27   11 13    51    17
    52313890 18262    11   38    31 13 22    19
    */
    public void leerConsultas(Scanner arch){
      int dniPaciente, codigoMedico, horaInicio, minutoInicio, segundoInicio, horaFin, minutoFin, segundoFin;
      int tiempoInicio = 0, tiempoFin = 0;
      
      while(arch.hasNext()){
        dniPaciente = arch.nextInt();
        codigoMedico = arch.nextInt();
        horaInicio = arch.nextInt();
        minutoInicio = arch.nextInt();
        segundoInicio = arch.nextInt();
        horaFin = arch.nextInt();
        minutoFin = arch.nextInt();
        segundoFin = arch.nextInt();
        
        tiempoInicio = horaInicio * 3600 + minutoInicio * 60 + segundoInicio;
        tiempoFin = horaFin  * 3600 + minutoFin * 60 + segundoFin;
        double tiempoDeAtencion = tiempoFin - tiempoInicio;
        double tarifa = actualizarMedico(codigoMedico,tiempoDeAtencion);
        actualizarPaciente(dniPaciente,tiempoDeAtencion,tarifa);       
      }
      
    }
    
    public double actualizarMedico(int codigoMedico,double tiempoDeAtencion){
      double tarifa = 0;
      for(Medico medico : this.medicos){
        if(medico.GetCodigo() == codigoMedico){
            tarifa = medico.GetTarifa();//tarifa del medico
            medico.SetTiempoTotal( medico.GetTiempoTotal() + tiempoDeAtencion/3600 );
            medico.SetIngresosTotales( medico.GetIngresosTotales() + (tiempoDeAtencion * tarifa)/3600 );
            medico.SetCantidadDeConsultas( medico.GetCantidadDeConsultas() + 1 );
            break;
        }
      }
      return tarifa;
    }

    public void actualizarPaciente(int dniPaciente,double tiempoDeAtencion,double tarifa){
      //double gasto = 0;
        for(Paciente paciente : this.pacientes){
          if(paciente.GetDni() == dniPaciente){
              paciente.SetTiempoTotal( paciente.GetTiempoTotal() + tiempoDeAtencion/3600 );
              paciente.SetGastosTotales( paciente.GetGastosTotales() + (tiempoDeAtencion * tarifa)/3600 );
              paciente.SetCantidadDeConsultas( paciente.GetCantidadDeConsultas() + 1 );
              break;
          }
        }
    }
	public void mostrarMedicos(){
 //System.out.println("Reporte Medicos:");
		for(Medico medico : this.medicos){
			medico.imprimirMedico();	
		}
	}
        public void mostrarPaciente(){
   //     System.out.println("Reporte Pacientes:");
		for(Paciente paciente : this.pacientes){
			paciente.imprimirPaciente();	
		}
}

}
