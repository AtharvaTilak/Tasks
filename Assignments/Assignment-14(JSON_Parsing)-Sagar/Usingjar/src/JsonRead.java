import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.FileReader;
import java.io.IOException;

public class JsonRead {
    public static void main(String[] args) throws IOException, ParseException {
        JSONParser json = new JSONParser();
        try (FileReader file = new FileReader("list.json")){
            Object obj = json.parse(file);
            JSONObject list = (JSONObject) obj;

            String name = (String) list.get("Name");
            Integer rollno = (Integer) list.get("RollNo");
            String branch = (String) list.get("Branch");
            Object subjects = (Object) list.get("Subjects");

            System.out.println("Name: " + name);
            System.out.println("RollNo: " + rollno);
            System.out.println("Branch: " + branch);
            System.out.println("Subjects: " + subjects);
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (ParseException e) {
            throw new RuntimeException(e);
        }

    }
}