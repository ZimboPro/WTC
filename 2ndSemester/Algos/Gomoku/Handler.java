import java.awt.Color;
import java.awt.Graphics;
import java.util.LinkedList;

/*
    handles the game objects, adding, removing and rendering of object
*/

public class Handler {

    LinkedList<GameObject> objs = new LinkedList<GameObject>();
    int[][] brd = new int[19][19];
    int turn = 1;
    public void tick()
    {
        for (int i = 0; i < objs.size(); i++)
        {
            GameObject temp = objs.get(i);
            temp.tick();
        }
    }

    public void render(Graphics g)
    {
        int x = 0;
        while (x < 19)
        {
            int y = 0;
            while (y < 19)
            {
                if (this.brd[y][x] == 1) g.setColor(Color.white);
                else if (this.brd[y][x] == 2) g.setColor(Color.black);
                if (this.brd[y][x] > 0) g.fillOval(((x * 35) + 40), ((y * 35) + 38), 20, 20);
                y++;
            }
            x++;
        }/*
        for (int i = 0; i < objs.size(); i++)
            {
                GameObject temp = objs.get(i);
                temp.render(g);
            }*/
    }

    public void addObj(GameObject obj)
    {
        this.objs.add(obj);
    }

    public void removeObj(GameObject obj)
    {
        this.objs.remove(obj);
    }

}