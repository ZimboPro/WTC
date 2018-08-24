
public class Legal extends Board{

    public Boolean LegalMove(int r, int c){
        if (this.valid_place(r, c) == true)
        {
            int[][]temp = this.board;
            if (capture(temp, r, c) == true) return (true);
            return (dble_three(temp, r, c));
        }
        return (false);
    }

    Boolean capture(int[][] arr, int r, int c){
        return (true);
    }

    Boolean dble_three(int[][] arr, int r, int c){
        return (true);
    }

}