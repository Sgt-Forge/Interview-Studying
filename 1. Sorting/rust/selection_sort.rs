pub fn selection_sort(array: &mut [i32]){
    let len = array.len();
    for sorted_ind in 0..len {
        let mut smallest = sorted_ind;
        for unsorted_ind in (sorted_ind + 1)..len {
            if array[unsorted_ind] < array[smallest]{
                smallest = unsorted_ind
            }
        }
        array.swap(smallest, sorted_ind);
    }
}

fn main() {
    let mut array: [i32; 5] = [5,4,3,2,1];
    selection_sort(&mut array);
    println!("Sorted: {:?}\n", array);
}