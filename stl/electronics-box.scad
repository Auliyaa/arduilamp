include <boxes.scad>

translate(v=[0,0,22.5]) difference() {
    roundedBox([30,95,45], 5, true);
    translate(v=[0,0,2.5]) roundedBox([25,90,45], 5, true);
    rotate([90,0,0]) roundedBox([7.5,4,300], 0.75, true);
}

translate(v=[35,0,4.1]) difference() {
    union() {
        roundedBox([30,95,8.2], 5, true);
        translate(v=[0,0,2.5]) difference() {
            roundedBox([25,90,10.2], 5, true);
            roundedBox([21.5,87.5,10.2], 5, true);
        }
    }
    translate(v=[0,0,-4.1]) cylinder(h=9, r=3.875, $fn=100);
    translate(v=[0,-20,-4.1]) cylinder(h=9, r=3.875, $fn=100);
    translate(v=[0,20,-4.1]) cylinder(h=9, r=3.875, $fn=100);
}