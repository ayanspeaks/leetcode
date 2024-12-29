#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

const double EPS = 1e-9;

struct Point {
    double x, y;
};

// Cross product of two points (vectors)
double cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
}

// Convex Hull using Graham's scan
std::vector<Point> convex_hull(std::vector<Point>& P) {
    size_t n = P.size(), k = 0;
    if (n <= 1) return P;
    std::sort(P.begin(), P.end(), [](const Point& a, const Point& b) {
        return a.x < b.x || (std::abs(a.x - b.x) < EPS && a.y < b.y);
    });
    std::vector<Point> H(2*n);
    // Lower hull
    for (size_t i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= EPS) k--;
        H[k++] = P[i];
    }
    // Upper hull
    for (size_t i = n-1, t = k+1; i > 0; --i) {
        while (k >= t && cross(H[k-2], H[k-1], P[i-1]) <= EPS) k--;
        H[k++] = P[i-1];
    }
    H.resize(k-1);
    return H;
}

// Function to compute the minimum area enclosing rectangle
void min_bounding_rectangle(const std::vector<Point>& hull, int& min_length, int& min_width) {
    size_t n = hull.size();
    if (n == 0) return;

    double min_area = std::numeric_limits<double>::infinity();
    int best_length = 0, best_width = 0;

    for (size_t i = 0; i < n; ++i) {
        // Edge from hull[i] to hull[(i+1)%n]
        Point p0 = hull[i];
        Point p1 = hull[(i+1)%n];

        // Edge vector
        double ex = p1.x - p0.x;
        double ey = p1.y - p0.y;
        double elen = std::hypot(ex, ey);
        if (elen == 0) continue;
        // Normalized edge vector
        double ux = ex / elen;
        double uy = ey / elen;

        // Perpendicular vector
        double vx = -uy;
        double vy = ux;

        // Project all hull points onto the edge and its perpendicular
        double min_proj_u = std::numeric_limits<double>::infinity();
        double max_proj_u = -std::numeric_limits<double>::infinity();
        double min_proj_v = std::numeric_limits<double>::infinity();
        double max_proj_v = -std::numeric_limits<double>::infinity();

        for (const auto& p : hull) {
            double dx = p.x - p0.x;
            double dy = p.y - p0.y;
            double proj_u = dx * ux + dy * uy;
            double proj_v = dx * vx + dy * vy;
            min_proj_u = std::min(min_proj_u, proj_u);
            max_proj_u = std::max(max_proj_u, proj_u);
            min_proj_v = std::min(min_proj_v, proj_v);
            max_proj_v = std::max(max_proj_v, proj_v);
        }

        double length = max_proj_u - min_proj_u;
        double width = max_proj_v - min_proj_v;

        int length_int = static_cast<int>(std::ceil(length - EPS));
        int width_int = static_cast<int>(std::ceil(width - EPS));
        double area = static_cast<double>(length_int * width_int);

        if (area < min_area - EPS) {
            min_area = area;
            best_length = length_int;
            best_width = width_int;
        } else if (std::abs(area - min_area) < EPS) {
            std::vector<int> dims = {length_int, width_int};
            std::sort(dims.begin(), dims.end());
            std::vector<int> best_dims = {best_length, best_width};
            std::sort(best_dims.begin(), best_dims.end());
            if (dims < best_dims) {
                best_length = length_int;
                best_width = width_int;
            }
        }
    }

    std::vector<int> dims = {best_length, best_width};
    std::sort(dims.begin(), dims.end());
    min_length = dims[0];
    min_width = dims[1];
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Point> polygon(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> polygon[i].x >> polygon[i].y;
    }

    // Compute the convex hull of the input polygon
    std::vector<Point> hull = convex_hull(polygon);

    int min_length = 0, min_width = 0;
    min_bounding_rectangle(hull, min_length, min_width);

    std::cout << min_length << " " << min_width;
    return 0;
}