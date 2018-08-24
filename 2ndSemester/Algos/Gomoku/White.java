import java.awt.Color;
import java.awt.Graphics;

/*
    creates a white piece and renders it
*/

public class White extends GameObject{

    public White(int r, int c, ID id, Player player)
    {
        super(r, c, id, player);
    }

    public void tick()
    {

    }

    public void render(Graphics g)
    {
      /*  System.out.println("Render White");
        g.setColor(Color.white);
        int x = c * 35 + 35;
        int y = r * 35 + 35;
        System.out.println("Render");
        System.out.println(x + " ," + y);
        g.fillOval(c * 100, r * 35 + 35, 20, 20);*/
    }

}