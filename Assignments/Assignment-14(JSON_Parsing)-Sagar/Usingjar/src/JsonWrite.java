import org.json.simple.JSONObject;

import java.io.FileWriter;
import java.io.IOException;

public class JsonWrite {
    public static void main(String[] args) throws IOException {
        JSONObject subjects = new JSONObject();
        subjects.put("Maths", 45);
        subjects.put("Physics", 56);
        subjects.put("Chemistry", 78);

        JSONObject students = new JSONObject();
        students.put("Name", "Atharva Sachin Tilak");
        students.put("RollNO", 19);
        students.put("Branch", "PCM");
        students.put("Subjects", subjects);

        FileWriter file = new FileWriter("list.json");
        file.write(students.toJSONString());
        file.flush();

    }

}
