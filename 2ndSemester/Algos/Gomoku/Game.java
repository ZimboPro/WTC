import java.awt.*;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.*;
import javax.imageio.ImageIO;
import javax.sound.midi.SysexMessage;
import java.awt.event.*;

/*
    main class calling all the other classes and methods
*/

public class Game extends Canvas implements Runnable{

    private static final long serialVersionUID = 0000000000001L;

    public static final int WIDTH = 1080, HEIGHT = 720;
    private Thread thread;
    private boolean running = false;
    private Handler handler;

    public Game(){
        handler = new Handler();
        new Window(WIDTH, HEIGHT, "Gomoku", this);
        int i = 0;
        while (i < 19)
        {
            int j = 0;
            while (j < 0)
            {
                handler.brd[i][j] = 0;
                j++;
            }
            i++;
        }
        this.addMouseListener(new MouseGame(handler));
    }

    public synchronized void start(){
        thread = new Thread(this);
        thread.start();
        running = true;
    }

    public synchronized void stop(){
        try{
            thread.join();
            running = false;
        }
        catch(Exception e){
            e.printStackTrace();
        }
    } 

    public void run(){
        long lastTime =System.nanoTime();
        double amountOfTicks = 60.0;
        double ns = 1000000000 / amountOfTicks;
        double delta = 0;
        long timer = System.currentTimeMillis();
        int frames = 0;
        while (running){
            long now = System.nanoTime();
            delta += (now - lastTime) / ns;
            while (delta >= 1){
                tick();
                delta--;
            }
            if (running)
                render();
            frames++;
            if (System.currentTimeMillis() - timer > 1000){
                timer += 1000;
                //System.out.println("FPS: " + frames);
                frames = 0;
            }
        }
        stop();
    }

    private void tick(){
        handler.tick();
    }

    private BufferedImage image;

    private void render(){
        BufferStrategy bs = this.getBufferStrategy();
        if (bs == null){
            this.createBufferStrategy(3);
            return ;
        }

        Graphics g = bs.getDrawGraphics();

        try{
            image = ImageIO.read(getClass().getResourceAsStream("board_2.png"));
        }
        catch (IOException e){
            e.printStackTrace();
        }

        image.getScaledInstance(720, 720, Image.SCALE_DEFAULT);

        g.setColor(Color.darkGray);
        g.fillRect(700, 0, WIDTH, HEIGHT);
        g.drawImage(image, 0, 0, 700, 700, null);

        handler.render(g);

        g.dispose();
        bs.show();
    }

    public static void main(String[] args){
        new Game();
    }
}