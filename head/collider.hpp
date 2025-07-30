struct Collider2{
	double left, right;
	double top, bot;

	Collider2(double l = 1, double r = 1, double t = 1, double b = 1) : left(l), right(r), top(t), bot(b);

	bool checkCollision(const Collider2& c){
		return !(right < c.left || left > b.right || bot < c.top || top > c.bot);
	}
};


