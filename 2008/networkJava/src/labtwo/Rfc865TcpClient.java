import java.net.InetAddress;
import java.net.SocketAddress;

public class Rfc865TcpClient {
 
    public static void main(String[] argv) {
    //
    // 1. Establish TCP connection with server
    //
    Socket socket = null;
    try {
        socket = new Socket();
        InetAddress clientAddr = InetAddress.getLocalHost();
        socket.connect(clientAddr,17);
    } 
    catch (Exception e) {
        System.out.println("Socket Error!");
    }
    
    try {
        //
        // 2. Send TCP request to server
        //
        OutputStream os = socket.getOutputStream();
        PrintWriter writer = new PrintWriter(output, true);
        writer.println("Hello Server! This is the client!");
        os.write(requestBuf);
        
        //
        // 3. Receive TCP reply from server
        //
        InputStream is = socket.getInputStream();
        BufferedReader reader = new BufferedReader(new InputStreamReader(input));
        String line = reader.readLine();    // reads a line of text
        System.out.println(line);
    } 
    catch (IOException ex) {
        System.out.println("Server exception: " + ex.getMessage());
        ex.printStackTrace();
    }
}
}
   