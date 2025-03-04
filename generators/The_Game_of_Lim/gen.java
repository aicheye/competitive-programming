import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.concurrent.ThreadLocalRandom;

public class gen {
    public static void main(String[] args) {
        BufferedWriter bwi;
        BufferedWriter bwo;

        for (int i = 1; i <= 15; i++) {
            String input = "/home/aicheye/Code/Data/limhard/data" + i + "_limhard.in";
            String output = "/home/aicheye/Code/Data/limhard/data" + i + "_limhard.out";

            boolean yes;

            if (i == 1)
                yes = false;
            else if (i == 2)
                yes = true;
            else
                yes = ThreadLocalRandom.current().nextBoolean();

            System.out.println(yes);

            try {
                boolean pass = false;

                while (!pass) {
                    bwi = new BufferedWriter(new FileWriter(input));
                    bwo = new BufferedWriter(new FileWriter(output));

                    int P = ThreadLocalRandom.current().nextInt(1, (int) 1e6 + 1);

                    bwi.write("" + P + "\n");

                    long grundy = 0;
                    while (P-- > 0) {
                        long n = ThreadLocalRandom.current().nextLong(1, (long) 1e18 + 1);
                        int k = ThreadLocalRandom.current().nextInt(1, 101);

                        bwi.write("" + n + " " + k + "\n");

                        grundy ^= (n - 1) % (k + 1);
                    }

                    if (grundy != 0 && yes) {
                        bwo.write("YES\n");
                        pass = true;
                    } else if (grundy == 0 && !yes) {
                        bwo.write("NO\n");
                        pass = true;
                    }

                    bwi.close();
                    bwo.close();
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
}
