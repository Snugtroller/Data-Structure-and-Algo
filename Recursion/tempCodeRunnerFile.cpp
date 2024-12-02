  // Printing the power set
    for (const auto& subset : result) {
        cout << "{ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "}\n";
    }