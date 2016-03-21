// CSE 101 Winter 2016, PA 3
// Due: February 19th, 2016 at 11:59 PM

#ifndef __GRID_SUM_CPP__
#define __GRID_SUM_CPP__

#include "TwoD_Array.hpp"
#include "GridSum.hpp"

#if 0
class GridSum {
public:
    GridSum(TwoD_Array<int>& grid);
    int query(int x1, int y1, int x2, int y2);

private:
    TwoD_Array<int> * pg->
};
#endif

GridSum::~GridSum()
{
	//grid.printOut();
	//pg->printOut();
}
GridSum::GridSum (TwoD_Array<int>& grid)
{
	int row = grid.getNumRows();
	int col = grid.getNumCols();
	pg = new TwoD_Array<int>(row, col);

	pg->at(0,0) = grid.at(0,0);
	for(int j=1; j<col; j++)
		pg->at(0,j) = pg->at(0, j-1) + grid.at(0, j);

	for(int i=1; i<row; i++)
		pg->at(i,0) = pg->at(i-1, 0) + grid.at(i, 0);;

	for(int i=1; i<row; i++)
		for(int j=1; j<col; j++)
			pg->at(i,j) = pg->at(i-1,j) + pg->at(i, j-1) - pg->at(i-1, j-1) + grid.at(i,j);

    //grid.printOut();
    //pg->printOut();
}

int GridSum::query (int x1, int y1, int x2, int y2)
{
	int left, right,diag;
	if(x1-1 <0 || y1-1 <0)
		diag = 0;
	else
		diag =  pg->at(x1-1, y1-1);
	if(x1-1<0)
		right = 0;
	else
		right = pg->at(x1-1,y2);
	if(y1 -1 < 0)
		left = 0;
	else
		left = pg->at(x2,y1-1);

	return diag + pg->at(x2, y2) - left -right;
}
#endif
