include <boxes.scad>

translate(v=[0,0,17.5]) difference() {
    union() {
        roundedBox([31,95,35], 5, false);
        translate(v=[0,0,2.5]) roundedBox([31,95,30], 5, true);
    }
    translate(v=[0,0,2.5]) roundedBox([26,90,35], 5, true);
    rotate([90,0,0]) roundedBox([8.5,4,300], 0.75, true);
}

translate(v=[-35,0,5.1]) difference() {
    union() {
        roundedBox([30,95,10.2], 5, false);
        translate(v=[0,0,2.5]) union() {
            roundedBox([30,95,5.2], 5, true);
            roundedBox([25,90,12.2], 5, true);
        }
    }
    translate(v=[0,0,2.5]) roundedBox([22,87,12.3], 5, true);
    translate(v=[0,0,-5.5]) cylinder(h=9, r=3.875, $fn=100);
    translate(v=[0,-20,-5.5]) cylinder(h=9, r=3.875, $fn=100);
    translate(v=[0,20,-5.5]) cylinder(h=9, r=3.875, $fn=100);
}