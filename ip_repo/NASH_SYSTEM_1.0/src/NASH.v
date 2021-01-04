module NASH (
    input clk,
    input [15:0] wspike,
    input [15:0] control,
    output [30:0] membrane_potential,
    output spike
  );

localparam THRESHOLD = 31'd200;
localparam V_RESET = 31'd0;

reg [30:0] reg_V;
reg [7:0] wspike_cnt;

assign spike = (reg_V > THRESHOLD )? 1'b1:1'b0;
assign membrane_potential = reg_V;
always @(posedge clk) begin
  if (control[0] == 1'b1) begin
    reg_V <= V_RESET;  // reset
    wspike_cnt <= 0;
  end else begin
    if (control[1] == 1'b1) begin
      if (wspike_cnt != control[15:8])    // different spikes
        reg_V <=  reg_V + wspike;
      wspike_cnt <= control[15:8];
    end else if (reg_V > THRESHOLD && control[2] == 1'b1)  begin
      reg_V <= V_RESET;
    end
  end
end

endmodule
