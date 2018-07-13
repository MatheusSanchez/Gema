public class Server {
	public static void main(String[] args) throws Exception {
		
		ServerSocket servidor = new ServerSocket(9669);

	    System.out.println("Porta 9669 aberta!"); // conectando com servidor
	    Socket cliente = servidor.accept();
	    PrintStream saida = new PrintStream(cliente.getOutputStream());
	    Scanner s = new Scanner(cliente.getInputStream());
	     
	    System.out.println("Nova conexão com o cliente " +   
	     	cliente.getInetAddress().getHostAddress());
	     
	    String[] tmp;

	    String r = s.nextLine(); // tmp[0] = I
	    tmp = r.split(" ");
		saida.println("Ola jogador de id:" + tmp[1]);


		int rodada = 0; // controle de rodadas
		Placar placar = new Placar();
		RolaDados dados = new RolaDados(5);
		int pontDados[] = new int[5]; // veotr com os inteiros dos dados que foram girados
		
		String troca = new String(); // string que informa quais dados o usuario quer trocar
		int addPlacar; //posicao placar para adicionar

		
		
		while(rodada < 10) {
			r = s.nextLine();
			String[] a = r.split(" ");


		}
	}
}