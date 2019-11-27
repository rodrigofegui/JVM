package controle;

import gui.InterfaceGrafica;

/**
 * Aplicação principal do controlador de estoque
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	07/09/2016
 */
public class ControladorEstoque {
	/**
	 * Estoque a ser considerado na aplicação
	 */
	public static Estoque estoque;
	
	/**
	 * Método principal a ser executado pela aplicação 
	 * @param args Argumentos via linha de comando
	 */
	public static void main(String[] args) {
		estoque = new Estoque();
		
		new InterfaceGrafica ();
	}
}
