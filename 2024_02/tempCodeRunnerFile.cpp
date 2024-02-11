struct Fish
{
    int y, x, dist;
    bool operator<(const Fish &b) const
    {
        if (dist == b.dist)
        {
            if (y == b.y)
                return x > b.x;
            return y > b.y;
        }
        return dist > b.dist;
    }
};