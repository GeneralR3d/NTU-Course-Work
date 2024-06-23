class ClientHandler implements Runnable {
    private Socket socket;
    
    
    public ClientHandler(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        //
        // 4. Receive TCP request from client
        //
        InputStream input = socket.getInputStream();
        BufferedReader reader = new BufferedReader(new InputStreamReader(input));
        String line = reader.readLine();    // reads a line of text
        System.out.println(line);
        //
        // 5. Send TCP reply to client
        //
        OutputStream output = socket.getOutputStream();
        PrintWriter writer = new PrintWriter(output, true);
        writer.println("This is a message sent to the client");
        socket.close();
    }
   }
   