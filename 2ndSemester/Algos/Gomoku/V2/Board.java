


public class Board{

    protected int[][] board = new int[19][19];

    protected Boolean valid_place(int r, int c)
    {
        if (this.board[r][c] == 0) return (true);
        return (false);
    } 

    protected Boolean place_move(int r, int c, ID p)
    {
        if (valid_place(r, c) == false) return (false);
        if (p == ID.Black) this.board[r][c] = 1;
        else if (p == ID.White) this.board[r][c] = 2;
        return (true);
    }

    protected Boolean init_brd(){
        int i = 0;
        int j = 0;
        while (i < 19){
            j = 0;
            while (j < 19){
                this.board[i][j] = 0;
                j++;
            }
            i++;
        }
        if (i == 19 && j == 19) return (true);
        return (false);
    }

    protected void cpy_to_brd(int[][] arr){
        int i = 0;
        while (i < 19){
            int j = 0;
            while (j < 19){
                this.board[i][j] = arr[i][j];
                j++;
            }
            i++;
        }
    }

    int[][] cpy_brd(){
        int[][] arr = new int[19][19];
        int i = 0;
        while (i < 19){
            int j = 0;
            while (j < 19){
                arr[i][j] = this.board[i][j];
                j++;
            }
            i++;
        }
        return (arr);
    }
}