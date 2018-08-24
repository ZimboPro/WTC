import java.awt.Color;
import java.awt.Graphics;

/*
    creates an instance of a black piece
    and renders it
*/

public class Black extends GameObject{

    public Black(int r, int c, ID id, Player player)
    {
        super(r, c, id, player);
    }

    public void tick()
    {

    }

    public void render(Graphics g)
    {/*
        g.setColor(Color.black);
        g.fillOval(c * 35 + 35, r * 35 + 35, 20, 20);*/
    }

}