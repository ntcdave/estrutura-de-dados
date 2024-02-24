import java.util.LinkedList;
import java.util.Queue;

public class Fila {

    public static void main(String[] args) {
        // Criando uma instância da classe LinkedList para representar a fila
        Queue<String> fila = new LinkedList<>();

        // Adicionando elementos à fila
        fila.offer("Elemento 1");
        fila.offer("Elemento 2");
        fila.offer("Elemento 3");

        // Exibindo a fila
        System.out.println("Fila: " + fila);

        // Obtendo e removendo o elemento da frente da fila
        String removido = fila.poll();
        System.out.println("Elemento removido: " + removido);

        // Exibindo a fila após a remoção
        System.out.println("Fila após remoção: " + fila);

        // Obtendo o elemento da frente da fila sem removê-lo
        String frente = fila.peek();
        System.out.println("Elemento da frente: " + frente);
    }
}
