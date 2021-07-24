class PruebaHilo extends Thread {
    private String nombre;
    private int temporizador;

    public PruebaHilo( String s,int d ) {
        nombre = s;
        temporizador = d;
        }

    public void run() {
        // Retasamos la ejecución 
        try {
            sleep( temporizador );
        } catch( InterruptedException e ) {
            ;
        }

        // Mostramos el nombre
        System.out.println( "Hola Mundo! "+nombre+" "+temporizador);
        }
    }

public class MultiHola {
    public static void main( String args[] ) {
        PruebaHilo t1,t2,t3;
        t1 = new PruebaHilo( "Hilo 1",(int)(Math.random()*2000) );
        t2 = new PruebaHilo( "Hilo 2",(int)(Math.random()*2000) );
        t3 = new PruebaHilo( "Hilo 3",(int)(Math.random()*2000) );
        t1.start();
        t2.start();
        t3.start();
        }
    }