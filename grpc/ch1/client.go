import (
"context"
pb "github.com/grpc-up-and-running/samples/ch02/productinfo/go/proto"
"google.golang.org/grpc"
)

// Add product remote method
func (s *server) AddProduct(ctx context.Context, in *pb.Product) (
*pb.ProductID, error) {
// business logic
}

// Get product remote method
func (s *server) GetProduct(ctx context.Context, in *pb.ProductID) (
*pb.Product, error) {
// business logic
}


func main() {
lis, _ := net.Listen("tcp", port)
s := grpc.NewServer()
pb.RegisterProductInfoServer(s, &server{})
if err := s.Serve(lis); err != nil {
log.Fatalf("failed to serve: %v", err)
}
