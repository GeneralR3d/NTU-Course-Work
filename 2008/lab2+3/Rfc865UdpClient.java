package lab3;
import java.io.IOException;
import java.net.DatagramPacket;

import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketException;

public class Rfc865UdpClient{
	
	public static void main(String [] argv){
		
		byte[] replyBuf = new byte[256];
		
		DatagramSocket socket = null;
		try{
			socket = new DatagramSocket();
			//socket.bind(new InetSocketAddress(17));
		}
		catch( SocketException e){
			System.out.println("Client Socket Error!");
		}
		

		try{
		

			
			InetAddress clientAddr = InetAddress.getByName("hwlab1.scse.ntu.edu.sg");
			//InetAddress clientAddr = InetAddress.getByName("localhost");
			
			String requestString = "Hello "+clientAddr.getAddress().toString()+"Server! This is the meeeeee!";
			byte[] requestBuf = requestString.getBytes();
			
			DatagramPacket request = new DatagramPacket(requestBuf,requestBuf.length,clientAddr,17);
			socket.send(request);
			
			
			DatagramPacket reply = new DatagramPacket(replyBuf,replyBuf.length);
			socket.receive(reply);
			String replyString = new String(reply.getData(), 0, reply.getLength());
			System.out.println("Reply from server:"+ replyString);
		}
		catch (IOException e){}
			

		socket.close();		
				
	}
	
}