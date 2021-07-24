public class Act2EACondicional{
    public static void main( String args[] ){
    int numero1 = (int)(Math.random()*2000);
    int numero2 = (int)(Math.random()*2000);
    
    if(numero1 > numero2)
	System.out.println("El numero1 "+numero1+" es mayor a "+numero2);
    else
	System.out.println("El numero2 "+numero2+" es mayor a "+numero1);
    }
}