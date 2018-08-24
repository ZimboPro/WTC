import java.awt.Graphics;

/*
    parent class of the objects
*/

public abstract class GameObject{
    protected int r;
    protected int c;
    protected ID id;
    protected Player player;

    public GameObject(int r, int c, ID id, Player player)
    {
        this.r = r;
        this.c = c;
        this.id = id;
        this.player = player;
    }

    public abstract void tick();
    public abstract void render(Graphics g);

    public int getR(){
        return (r);
    }

    public int getC(){
        return (c);
    }

    public ID getID(){
        return (id);
    }

    public Player getPlayer(){
        return (player);
    }
}