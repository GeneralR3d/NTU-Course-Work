package labtwo;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketException;

public class Rfc865UdpClient {
	public static void main(String [] argv){
			
			byte[] replyBuf = new byte[256];
			
			DatagramSocket socket = null;
			try{
				socket = new DatagramSocket();
				//socket.bind(new InetSocketAddress(17));
			}
			catch(SocketException e){
				System.out.println("Socket Error!");
			}
			
	
			try{
				//communicate w own machine
//				String requestString = "Hello Server! This is the client!";
//				byte[] requestBuf = requestString.getBytes();
//				
//				InetAddress clientAddr = InetAddress.getByName("localhost");
//				DatagramPacket request = new DatagramPacket(requestBuf,requestBuf.length,clientAddr,17);
//				socket.send(request);
//				
//				
//				DatagramPacket reply = new DatagramPacket(replyBuf,replyBuf.length);
//				socket.receive(reply);
//				String replyString = new String(reply.getData(), 0, reply.getLength());
//				System.out.println(replyString);
				
				//communicate w lab server
			
				InetAddress clientAddr = InetAddress.getByName("hwlab1.scse.ntu.edu.sg");
				
				String requestString = "Ding Ren, SCEX," + clientAddr.getLocalHost() ;
				byte[] requestBuf = requestString.getBytes();
				DatagramPacket request = new DatagramPacket(requestBuf,requestBuf.length,clientAddr,17);
				socket.send(request);
				
				
				DatagramPacket reply = new DatagramPacket(replyBuf,replyBuf.length);
				socket.receive(reply);
				String replyString = new String(reply.getData(), 0, reply.getLength());
				System.out.println(replyString);
			}
			catch (IOException e){}
	}
}
