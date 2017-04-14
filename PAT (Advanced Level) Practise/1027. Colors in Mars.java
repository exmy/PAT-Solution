import java.util.Scanner;

public class Main {
  public static void main(String[] args) {

    Scanner in = new Scanner(System.in);
    int r = in.nextInt(), g = in.nextInt(), b = in.nextInt();

    System.out.println("#" + convert(r) + convert(g) + convert(b));
  }

  static String  convert(int val){
    StringBuffer ret = new StringBuffer();
    String let = "0123456789ABC";
    int v = val;

    while(val != 0){
      ret.append(  (let.charAt(val % 13)));
      val /= 13;
    }
    if(v < 13) ret.append("0");
    if(v == 0) ret.append("0");

    return ret.reverse().toString();
  }
}