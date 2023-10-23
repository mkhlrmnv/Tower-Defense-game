


class object {
public:
    virtual void attack();

    virtual void take_damage();


private:
    int _health_points;
    int _damage;
    int _range;
    int _attack_speed;
}