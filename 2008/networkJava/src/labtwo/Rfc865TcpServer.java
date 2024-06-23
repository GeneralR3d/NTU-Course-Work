import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Rfc865TcpServer {
 
    public static void main(String[] argv) {
        //
        // 1. Open TCP socket at well-known port
        //
        static ServerSocket parentSocket = null;
        try {
            parentSocket = new ServerSocket(17);
        } 
        catch (Exception e) {}
        
        while (true) {
            try {
            //
            // 2. Listen to establish TCP connection with clnt
            //
            Socket childSocket = parentSocket.accept();
            // 
            // 3. Create new thread to handle client connection
            //
            ClientHandler client = new ClientHandler(childSocket);
            Thread thread = new Thread(client);
            thread.start();
            } 
            catch (IOException e) {
                System.out.println("Server exception: " + e.getMessage());
                e.printStackTrace();
            }
        }
    }
}
   