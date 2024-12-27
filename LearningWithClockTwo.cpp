#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>

const double EPSILON = 1e-8;

enum RotationDirection {
    TURN_CLOCKWISE,
    TURN_COUNTERCLOCKWISE
};

double angle_distance(double from_angle, double to_angle, RotationDirection direction) {
    if (direction == TURN_CLOCKWISE) {
        return fmod((to_angle - from_angle + 360), 360);
    } else {
        return fmod((from_angle - to_angle + 360), 360);
    }
}

double compute_cost(double motion, int dir_cost, int rate_primary, int rate_secondary) {
    double initial_90 = std::min(motion, 90.0);
    double excess = std::max(0.0, motion - 90.0);
    return dir_cost * (initial_90 * rate_primary + excess * rate_secondary);
}

int main() {
    std::string current_time_str;
    std::getline(std::cin, current_time_str);
   
    int initial_hour_hand = std::stoi(current_time_str.substr(0, current_time_str.find(':')));
    int initial_minute_hand = std::stoi(current_time_str.substr(current_time_str.find(':') + 1));
   
    double current_hour_angle = (initial_hour_hand % 12) * 30.0; 
    double current_minute_angle = initial_minute_hand * 6.0;     

    int num_queries;
    std::cin >> num_queries;

    int cost_clockwise, cost_counterclockwise;
    std::cin >> cost_clockwise >> cost_counterclockwise;

    int primary_rate_hour, secondary_rate_hour;
    std::cin >> primary_rate_hour >> secondary_rate_hour;

    int primary_rate_minute, secondary_rate_minute;
    std::cin >> primary_rate_minute >> secondary_rate_minute;

    std::vector<int> target_angles(num_queries);
    for (int i = 0; i < num_queries; ++i) {
        std::cin >> target_angles[i];
    }

    double aggregated_cost = 0.0;

    for (int i = 0; i < num_queries; ++i) {
        int target_angle = target_angles[i];

        double lowest_cost = std::numeric_limits<double>::max();
        double optimal_hour_angle = current_hour_angle;
        double optimal_minute_angle = current_minute_angle;
        RotationDirection optimal_direction_hour = TURN_CLOCKWISE;
        RotationDirection optimal_direction_minute = TURN_COUNTERCLOCKWISE;
       
        for (int h_dir = 0; h_dir < 2; ++h_dir) {
            RotationDirection direction_hour = h_dir == 0 ? TURN_CLOCKWISE : TURN_COUNTERCLOCKWISE;
            RotationDirection direction_minute = direction_hour == TURN_CLOCKWISE ? TURN_COUNTERCLOCKWISE : TURN_CLOCKWISE;
           
            double inter_angle;
            if (direction_hour == TURN_CLOCKWISE) {
                inter_angle = fmod(current_minute_angle - current_hour_angle + 360, 360);
            } else {
                inter_angle = fmod(current_hour_angle - current_minute_angle + 360, 360);
            }
            double max_allowed_movement = inter_angle;

            
            for (int hour_mark = 0; hour_mark < 12; ++hour_mark) {
                double new_hour_angle = hour_mark * 30.0;
                double hour_movement = angle_distance(current_hour_angle, new_hour_angle, direction_hour);

                
                int hour_direction_cost = direction_hour == TURN_CLOCKWISE ? cost_clockwise : cost_counterclockwise;

                
                double hour_cost = compute_cost(hour_movement, hour_direction_cost, primary_rate_hour, secondary_rate_hour);

                
                std::vector<int> possible_angles = {target_angle, 360 - target_angle};

                for (int possible_angle : possible_angles) {
                    double new_minute_angle = fmod(new_hour_angle + possible_angle + 360, 360);

                    double minute_movement = angle_distance(current_minute_angle, new_minute_angle, direction_minute);
                    int minute_direction_cost = direction_minute == TURN_CLOCKWISE ? cost_clockwise : cost_counterclockwise;

                    
                    double minute_cost = compute_cost(minute_movement, minute_direction_cost, primary_rate_minute, secondary_rate_minute);

                    
                    double total_motion = hour_movement + minute_movement;

                    
                    if (total_motion - max_allowed_movement > EPSILON) {
                        continue; 
                    }

                    double candidate_total_cost = hour_cost + minute_cost;

                    if (candidate_total_cost < lowest_cost - EPSILON) {
                        lowest_cost = candidate_total_cost;
                        optimal_hour_angle = new_hour_angle;
                        optimal_minute_angle = new_minute_angle;
                        optimal_direction_hour = direction_hour;
                        optimal_direction_minute = direction_minute;
                    }
                }
            }
        }
        
        current_hour_angle = optimal_hour_angle;
        current_minute_angle = optimal_minute_angle;

        aggregated_cost += lowest_cost;
    }

    std::cout << static_cast<int>(std::round(aggregated_cost));

    return 0;
}