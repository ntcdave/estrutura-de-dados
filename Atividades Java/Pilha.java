import java.util.Stack;

public class Pilha {

    public static void main(String[] args) {
        // Criando uma instância da classe Stack para representar a pilha
        Stack<Integer> pilha = new Stack<>();

        // Adicionando elementos à pilha
        pilha.push(10);
        pilha.push(20);
        pilha.push(30);

        // Exibindo a pilha
        System.out.println("Pilha: " + pilha);

        // Obtendo o elemento no topo da pilha sem removê-lo
        int topo = pilha.peek();
        System.out.println("Elemento no topo: " + topo);

        // Removendo o elemento no topo da pilha
        int removido = pilha.pop();
        System.out.println("Elemento removido: " + removido);

        // Exibindo a pilha após a remoção
        System.out.println("Pilha após remoção: " + pilha);
    }
}
