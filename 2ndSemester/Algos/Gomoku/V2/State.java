

public class State extends Board{

    protected boolean GameState(){
        if (Hor() == true) return (true);
        else if (Vert() == true) return (true);
        else if (Diag() == true) return (true);
        return (false);
    }

    protected boolean Hor(){
        int r = 0;
        int c = 0;
        while (r < 19)
        {
            c = 0;
            while (c < 14)
            {
                if (this.board[r][c] > 0)
                {
                    if (this.board[r][c] == this.board[r][c + 1] && this.board[r][c] == this.board[r][c + 2] && this.board[r][c] == this.board[r][c + 3] && this.board[r][c] == this.board[r][c + 4] && this.board[r][c] > 0)
                        return (true);
                }
                c++;
            }
            r++;
        }
        return (false);
    }

    protected boolean Vert(){
        int r = 0;
        int c = 0;
        while (r < 14)
        {
            c = 0;
            while (c < 19)
            {
                if (this.board[r][c] > 0)
                {
                    if (this.board[r][c] == this.board[r + 1][c] && this.board[r][c] == this.board[r + 2][c] && this.board[r][c] == this.board[r + 3][c] && this.board[r][c] == this.board[r + 4][c] && this.board[r][c] > 0)
                        return (true);
                }
                c++;
            }
            r++;
        }
        return (false);
    }

    protected boolean Diag(){
        int r = 0;
        int c = 0;
        while (r < 14)
        {
            c = 0;
            while (c < 14)
            {
                if (this.board[r][c] > 0)
                {
                    if (this.board[r][c] == this.board[r + 1][c + 1] && this.board[r][c] == this.board[r + 2][c + 2] && this.board[r][c] == this.board[r + 3][c + 3] && this.board[r][c] == this.board[r + 4][c + 4])
                        return (true);
                    if (this.board[r][c + 4] == this.board[r + 1][c + 3] && this.board[r][c] == this.board[r + 2][c + 2] && this.board[r][c] == this.board[r + 3][c + 1] && this.board[r][c] == this.board[r + 4][c])
                        return (true);
                }
                c++;
            }
            r++;
        }
        return (false);
    }
}