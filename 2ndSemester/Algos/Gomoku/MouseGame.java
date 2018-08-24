import java.awt.event.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.*;
import java.lang.*;

/*
    initialises mouse usability and what to do when a click is registered
*/

public class MouseGame extends MouseAdapter
{

    private Handler handler;

    public MouseGame(Handler handler)
    {
        this.handler = handler;
    }

    public void mouseClicked(MouseEvent e){
        System.out.println("point");
        System.out.println(e.getX() + ", " + e.getY());
        if (e.getY() >= 35 && e.getY() <= 697 && e.getX() >= 35 && e.getX() <= 697)
        {
            int r = ((e.getY() - 35) / 35);
            int c = ((e.getX() - 35) / 35);
            System.out.println("R + C");
            System.out.println(r + ", " + c);
            System.out.println(((r * 35) + 35) + ", " + ((c * 35) + 52));
            handler.brd[r][c] = 2;
            handler.addObj(new Black(r, c, ID.Black, Player.Player1));
            handler.turn++;
        }
    }
}
