import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class tempo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int iterations = scan.nextInt();

        List<Event> events = new ArrayList<>();

        for (int i = 0, j = 0; i < iterations; i++, j++) {
            Event event = new Event(scan.next().charAt(0), scan.nextInt());
            if (i != 0 && event.type != 'T' && events.get(j - 1).type != 'T') {
                events.add(new Event('T', 1));
                j++;
            }
            events.add(event);
        }

        List<Response> respostas = new ArrayList<>();
        for (int i = 0; i < events.size(); i++) {
            if (events.get(i).type == 'R') {
                System.out.print(events.get(i).value + " ");
                int j = i;
                int timeSum = 0;
                do {
                    j++;
                    if (j == events.size()) {
                        timeSum = -1;
                        break;
                    }
                    if (events.get(j).type == 'T') {
                        timeSum += events.get(j).value;
                    }
                } while (!(events.get(j).type == 'E' &&
                        events.get(j).value == events.get(i).value));
                respostas.add(new Response(events.get(i).value, timeSum));
            }

            for (Response resposta : respostas) {

            }
        }


    }
}

class Event {
    public char type;
    public int value;

    public Event(char type, int value) {
        this.type = type;
        this.value = value;
    }
}

class Response {
    public int amigoId;
    public int value;

    public Response(int amigoId, int value) {
        this.amigoId = amigoId;
        this.value = value;
    }
}
