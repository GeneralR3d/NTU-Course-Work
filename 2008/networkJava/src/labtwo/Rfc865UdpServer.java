package labtwo;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketException;

public class Rfc865UdpServer {
	public static void main(String [] argv){
			
			byte[] requestBuf = new byte[256];
			
			DatagramSocket socket= null;
			try{
				socket = new DatagramSocket(17);
				//socket.bind(new InetSocketAddress(17));
			}
			catch( SocketException e){
				System.out.println("Socket Error!");
			}
			
			while(true){
				
				try{
					DatagramPacket request = new DatagramPacket(requestBuf,requestBuf.length);
					socket.receive(request);
					InetAddress clientAddr = request.getAddress();
					int portNum = request.getPort();
					
					String replyString = "Hello client! This is the server!";
					byte[] replyBuf = replyString.getBytes();
					
					DatagramPacket reply = new DatagramPacket(replyBuf,replyBuf.length,clientAddr,portNum);
					socket.send(reply);
				}
				catch (IOException e){}
				
			}
					
					
		}
}
