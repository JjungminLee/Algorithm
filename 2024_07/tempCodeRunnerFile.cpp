  for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == input)
            {
                v[i].second += 1;
            }
            else
            {
                v.push_back({input, 1});
            }
        }