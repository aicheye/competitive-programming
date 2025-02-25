import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.concurrent.ThreadLocalRandom;

public class gen {
    public static void main(String[] args) {
        BufferedWriter bwi;
        BufferedWriter bwo;

        boolean yes = ThreadLocalRandom.current().nextBoolean();

        for (int i = 1; i <= 40; i++) {
            String input = "generators/The_Game_of_Lim/data/data" + i + "_limhard.in";
            String output = "generators/The_Game_of_Lim/data/data" + i + "_limhard.out";

            try {
                bwi = new BufferedWriter(new FileWriter(input));
                bwo = new BufferedWriter(new FileWriter(output));

                int P = ThreadLocalRandom.current().nextInt(1, (int) 1e6 + 1);

                bwi.write("" + P + "\n");

                long grundy = 0;
                while (P-- > 0) {
                    long n = ThreadLocalRandom.current().nextLong(1, (long) 1e18 + 1);
                    int k = ThreadLocalRandom.current().nextInt(1, 13);

                    bwi.write("" + n + " " + k + "\n");

                    grundy ^= (n - 1) % (k + 1);
                }

                if (grundy != 0) {
                    if (yes)
                        bwo.write("YES\n");
                    else
                        i--;
                } else if (grundy == 0) {
                    if (!yes)
                        bwo.write("NO\n");
                    else
                        i--;
                }

                bwi.close();
                bwo.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
}
