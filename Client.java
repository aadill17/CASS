package Client;

import java.io.*;
import java.net.*;
import java.security.*;
import javax.crypto.*;
/**
 *
 * @author user
 */
public class Client {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     * @throws java.net.SocketException
     */
    public static void main(String[] args) throws IOException , SocketException, InvalidKeyException,IllegalBlockSizeException, NoSuchAlgorithmException, Exception{
        // TODO code application logic here
        File f1=new File("C:\\Documents and Settings\\Administrator\\Desktop\\Client\\Original.txt");
        FileReader fr=new FileReader(f1);
        BufferedReader br=new BufferedReader(fr);
        Socket s=new Socket("127.0.0.1",1234);
        DataInputStream sc1;
        sc1 = new DataInputStream(s.getInputStream());
        String no=br.readLine();
        SecretKey key = KeyGenerator.getInstance("DES").generateKey();
        DesEncrypter  encrypter = new DesEncrypter (key);
        String encrypted = encrypter.encrypt(no);

        
        PrintStream p=new PrintStream(s.getOutputStream());
        p.println(encrypted);
        String temp;
        temp = sc1.readLine();
        String s3=encrypter.decrypt(temp);
        
        File file2=new File("C:\\Documents and Settings\\Administrator\\Desktop\\Client\\out.txt");
        FileWriter fw=new FileWriter(file2);
        BufferedWriter bw=new BufferedWriter(fw);
        bw.write(s3);
        bw.close();
        
        
    }
    
}

class DesEncrypter {
  Cipher ecipher;

  Cipher dcipher;

  DesEncrypter(SecretKey key) throws Exception {
    ecipher = Cipher.getInstance("DES");
    dcipher = Cipher.getInstance("DES");
    ecipher.init(Cipher.ENCRYPT_MODE, key);
    dcipher.init(Cipher.DECRYPT_MODE, key);
  }

  public String encrypt(String str) throws Exception {
    // Encode the string into bytes using utf-8
    byte[] utf8 = str.getBytes("UTF8");

    // Encrypt
    byte[] enc = ecipher.doFinal(utf8);

    // Encode bytes to base64 to get a string
    return new sun.misc.BASE64Encoder().encode(enc);
  }

  public String decrypt(String str) throws Exception {
    // Decode base64 to get bytes
    byte[] dec = new sun.misc.BASE64Decoder().decodeBuffer(str);

    byte[] utf8 = dcipher.doFinal(dec);

    // Decode using utf-8
    return new String(utf8, "UTF8");
  }
}